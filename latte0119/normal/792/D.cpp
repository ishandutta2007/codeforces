#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,Q,H;

int vec[100];
int h;

signed main(){
    cin>>N>>Q;
    for(int i=0;i<60;i++)if(N+1==(1ll<<(i+1)))H=i;
    while(Q--){
        int v;cin>>v;
        string s;cin>>s;
        int t=v;
        for(h=0;h<=H;h++){
            if((1ll<<(H-h))==t)break;

            else if((1ll<<(H-h))>t){
                vec[h]=1;
            }
            else{
                t-=1ll<<(H-h);
                vec[h]=2;
            }
        }


        for(int i=0;i<s.size();i++){
            if(s[i]=='U'){
                if(h==0)continue;
                if(vec[h-1]==1){
                    v+=1ll<<(H-h);
                }
                else{
                    v-=1ll<<(H-h);
                }
                h--;
            }
            else if(s[i]=='L'){
                if(h==H)continue;
                vec[h++]=1;
                v-=1ll<<(H-h);
            }
            else{
                if(h==H)continue;
                vec[h++]=2;
                v+=1ll<<(H-h);
            }
        }
        cout<<v<<endl;
    }
    return 0;
}