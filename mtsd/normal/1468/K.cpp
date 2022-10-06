#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
// L R U D
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> a(n);
        rep(i,n){
            if(s[i]=='L'){
                a[i] = 0;
            }else if(s[i]=='R'){
                a[i] = 1;
            }else if(s[i]=='U'){
                a[i] = 2;
            }else{
                a[i] = 3;
            }
        }
        int X = 0;
        int Y = 0;
        vector<pair<int,int> >cand;
        rep(i,n){
            X += dx[a[i]];
            Y += dy[a[i]];
            if(X!=0||Y!=0)cand.push_back(make_pair(X,Y));
        }
        pair<int,int> res = {0,0};
        for(auto&x:cand){
            X = 0;
            Y = 0;
            rep(i,n){
                if(make_pair(X+dx[a[i]],Y+dy[a[i]]) != x){
                    X += dx[a[i]];
                    Y += dy[a[i]];
                }
            }
            if(X==0&&Y==0){
                res = x;
            }
        }
        cout << res.first << " " << res.second << "\n";
    }
    return 0;
}