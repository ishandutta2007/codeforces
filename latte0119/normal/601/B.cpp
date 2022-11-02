#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N,Q;
int A[100000];
int X[100000];

int L[100000],R[100000];

void query(){
    int l,r;cin>>l>>r;
    l--;r--;

    {
        stack<int>st;
        for(int i=l;i<r;i++){
            while(st.size()&&X[st.top()]<X[i])st.pop();
            L[i]=st.empty()?l:(st.top()+1);
            st.push(i);
        }
    }

    {
        stack<int>st;
        for(int i=r-1;i>=l;i--){
            while(st.size()&&X[st.top()]<=X[i])st.pop();
            R[i]=(st.empty()?r:st.top())-1;
            st.push(i);
        }
    }

    long long ans=0;
    for(int i=l;i<r;i++){
        ans+=(i-L[i]+1)*(R[i]-i+1)*X[i];
    }
    //cout<<"L :";for(int i=l;i<r;i++)cout<<L[i]<<" ";cout<<endl;
    //cout<<"R :";for(int i=l;i<r;i++)cout<<R[i]<<" ";cout<<endl;
    cout<<ans<<endl;
}

signed main(){
    cin>>N>>Q;
    rep(i,N)cin>>A[i];
    rep(i,N-1)X[i]=abs(A[i+1]-A[i]);

    //cout<<"X :";rep(i,N-1)cout<<X[i]<<" ";cout<<endl;
    while(Q--)query();
    return 0;
}