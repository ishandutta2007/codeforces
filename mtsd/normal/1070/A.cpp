#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define len(v) (v).size()
#define INF 1000000005
using namespace std;
#define int long long 
typedef pair<int,int>P;

signed main(){
    int d,s;
    cin >> d >> s;    
    vector<vector<bool> > flag(5010,vector<bool>(510));
    queue<pair<pair<int,int>,string> > q;
    for(int i=0;i<10;i++){
        if(!flag[i][i%d]){
            flag[i][i%d] = 1;
            q.push(MP(MP(i,i%d),to_string(i)));
        }
    }
    string ans;
    while(!q.empty()){
        auto x = q.front();
        int keta = x.first.first;
        int md = x.first.second;
        string str  = x.second;
        if(keta==s&&md==0){
            ans = str;
            break;
        }
        q.pop();
        for(int i=0;i<10;i++){
            if(keta+i<=s&&!flag[keta+i][(md*10+i)%d]){
                flag[keta+i][(md*10+i)%d] = 1;
                q.push(MP(MP(keta+i,(md*10+i)%d),str+to_string(i)));
            }
        }
    }
    if(flag[s][0]){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}