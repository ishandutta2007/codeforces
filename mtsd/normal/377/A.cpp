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
char s[510][510];
bool flag[510][510];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    Fill(s,'#');
    rep(i,n){
        rep(j,m)cin >> s[i+1][j+1];
    }
    auto check = [&](int i,int j)->bool{
        if(s[i][j]!='.')return false;
        return true;
    };
    auto dfs = [&](auto&& f,int i,int j)->void{
        if(k==0)return;
        if(flag[i][j])return;
        flag[i][j] = 1;
        rep(z,4){
            if(check(i+dx[z],j+dy[z])){
                f(f,i+dx[z],j+dy[z]);
            }
        }
        if(k==0)return;
        s[i][j] = 'X';
        k--;
    };
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check(i,j))dfs(dfs,i,j);
        }
    }
    
    rep(i,n){
        rep(j,m){
            cout << s[i+1][j+1];
        }
        cout << "\n";
    }
    return 0;
}