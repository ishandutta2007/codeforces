#include<bits/stdc++.h>
using namespace std;

#define int long long
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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}


int M;
int T[1000000],V[1000000];
inline void add(int t,int v=0){
    T[M]=t;
    V[M]=v;
    M++;
}
signed main(){
    int N;
    scanf("%lld",&N);
    priority_queue<int,vector<int>,greater<int>>que;
    char S[10];
    int A;
    for(int i=0;i<N;i++){
        scanf("%s",S);
        if(S[0]=='i'){//insert
            scanf("%lld",&A);
            add(0,A);
            que.push(A);
        }
        else if(S[0]=='r'){//removeMin
            if(que.size()==0){
                add(0,1);
                que.push(1);
            }
            add(1);
            que.pop();
        }
        else{//getMin
            scanf("%lld",&A);
            while(que.size()&&que.top()<A){
                add(1);
                que.pop();
            }
            if(que.size()==0||que.top()>A){
                add(0,A);
                que.push(A);
            }
            add(2,A);
        }
    }

    printf("%lld\n",M);
    for(int i=0;i<M;i++){
        if(T[i]==0)printf("insert %lld\n",V[i]);
        else if(T[i]==1)puts("removeMin");
        else printf("getMin %lld\n",V[i]);
    }
    return 0;
}