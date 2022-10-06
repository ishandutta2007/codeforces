#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
ll dp[21][21][1<<8];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
    int n,m;
    cin >> n >> m;
    vector<string >s(n);
    rep(i,n)cin >> s[i];
    int c = 0;
    int b = 0;
    map<int,pair<int,int> > mp;
    vector<pair<int,int> > bomb;
    pair<int,int> S;
    rep(i,n){
        rep(j,m){
            if('1'<=s[i][j]&&s[i][j]<='9'){
                c++;
                mp[s[i][j]-'1'] = MP(i,j);
            }else if(s[i][j]=='B'){
                b++;
                bomb.push_back(MP(i,j));
            }else if(s[i][j]=='S'){
                S = MP(i,j);
            }
        }
    }
    int k = b + c;
    vector<pair<int,int>> object(k);
    rep(i,c){
        object[i] = mp[i];
    }
    rep(i,b){
        object[c+i] = bomb[i];
    }
    vector<ll> val(k,-inf);
    rep(i,c)cin >> val[i];
    Fill(dp,inf);
    dp[S.first][S.second][0] = 0;
    priority_queue<tuple<int,int,int,int> > pq;
    pq.push(make_tuple(0,S.first,S.second,0));
    auto check = [&](int i,int j)->bool{
        if(i<0||i>=n||j<0||j>=m)return false;
        if(s[i][j]!='.'&&s[i][j]!='S')return false;
        return true;
    };
    while(!pq.empty()){
        auto [cost,i,j,state] = pq.top();
        cost = -cost;
        if(dp[i][j][state]!=cost)continue;
        pq.pop();
        rep(zz,4){
            int ni = i + dx[zz];
            int nj = j + dy[zz];
            if(!check(ni,nj))continue;
            if(ni!=i){
                int nstate = state;
                rep(zz,k){
                    if(object[zz].second > nj)continue;
                    if(i<ni){
                        if(object[zz].first == ni){
                            nstate ^= (1<<zz);
                        }
                    }else{
                        if(object[zz].first == i){
                            nstate ^= (1<<zz);
                        }
                    }
                }
                if(chmin(dp[ni][nj][nstate],(ll)cost + 1)){
                    pq.push(make_tuple(-cost-1,ni,nj,nstate));
                }
            }else{
                if(chmin(dp[ni][nj][state],(ll)cost + 1)){
                    pq.push(make_tuple(-cost-1,ni,nj,state));
                }
            }
        }
    }   
    ll ma = 0;
    rep(bit,1<<k){
        ll t = -dp[S.first][S.second][bit];
        rep(zz,k){
            if((bit>>zz)&1){
                t += val[zz];
            }
        }
        chmax(ma,t);
    }
    cout << ma << endl;
    return 0;
}