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

const int INF=1001001001;
const int INFLL=1001001001001001001ll;
const int mod=1000000007;
inline void am(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int N;

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>N;

    stack<int>st;
    priority_queue<int,vint,greater<int>>pq;

    int ans=0;
    int cur=0;
    rep(i,2*N){
        string s;
        int d;
            cin>>s;
        if(s=="add"){
            cin>>d;
            st.push(d);
        }
        else{
            cur++;
            if(st.size()){
                if(st.top()==cur){
                    st.pop();
                    continue;
                }
                else{
                    ans++;
                    while(st.size()){
                        pq.push(st.top());
                        st.pop();
                    }
                }
            }
            pq.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}