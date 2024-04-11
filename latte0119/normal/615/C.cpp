#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int main(){
    string A,B,T;
    cin>>A>>T;
    B=A;reverse(all(B));

    rep(i,T.size()){
        if(find(all(A),T[i])==A.end()){
            cout<<-1<<endl;
            return 0;
        }
    }
    vpint ans;
    for(int i=0;i<T.size();){
        int ma=-1,tmp;
        rep(j,A.size()){
            for(int k=0;;k++){
                if(j+k==A.size()||T[i+k]!=A[j+k]){
                    if(ma<k){
                        ma=k;
                        tmp=j+1;
                    }
                    break;
                }
            }
        }
        rep(j,B.size()){
            for(int k=0;;k++){
                if(j+k==B.size()||T[i+k]!=B[j+k]){
                    if(ma<k){
                        ma=k;
                        tmp=-j-1;
                    }
                    break;
                }
            }
        }
        if(tmp>0){
            ans.pb(pint(tmp,tmp+ma-1));
        }
        else{
            ans.pb(pint(A.size()+tmp+1,A.size()+tmp+1-ma+1));
        }
        i+=ma;
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<ans[i].first<<" "<<ans[i].second<<endl;

    return 0;
}