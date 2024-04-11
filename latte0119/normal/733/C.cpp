#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;
int A[555];
int K;
int B[555];

signed main(){
    cin>>N;rep(i,N)cin>>A[i];
    cin>>K;rep(i,K)cin>>B[i];

    vpint ans;
    int cur=0;
    rep(k,K){
        int sum=0;
        int next=cur;
        vector<int>v;
        while(next<N&&sum<B[k]){
            v.pb(A[next]);
            sum+=A[next++];
        }
        if(sum!=B[k]){
            cout<<"NO"<<endl;
            return 0;
        }
        cur=next;
        while(v.size()>1){
            int ma=*max_element(all(v));
            bool ok=false;
            rep(i,v.size()){
                if(v[i]!=ma)continue;
                if(i&&v[i-1]!=ma){
                    ok=true;
                    ans.pb({k+1+i,0});
                    v[i]+=v[i-1];
                    v.erase(v.begin()+i-1);
                    break;
                }
                if(i+1<v.size()&&v[i+1]!=ma){
                    ok=true;
                    ans.pb({k+1+i,1});
                    v[i]+=v[i+1];
                    v.erase(v.begin()+i+1);
                    break;
                }
            }
            if(!ok){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    if(cur!=N){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    rep(i,ans.size()){
        cout<<ans[i].fi<<" ";
        if(ans[i].se==0)cout<<"L"<<endl;
        else cout<<"R"<<endl;
    }
    return 0;
}