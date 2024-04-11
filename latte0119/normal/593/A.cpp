#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N;
string S[100];

int main(){
    cin>>N;
    rep(i,N)cin>>S[i];

    int ma=0;


    for(char a='a';a<='z';a++){
        for(char b='b';b<='z';b++){
            int sum=0;
            rep(i,N){
                bool flag=true;
                rep(j,S[i].size()){
                    if(S[i][j]==a)continue;
                    if(S[i][j]==b)continue;
                    flag=false;
                }
                if(flag)sum+=S[i].size();
            }
            chmax(ma,sum);
        }
    }

    cout<<ma<<endl;

    return 0;
}