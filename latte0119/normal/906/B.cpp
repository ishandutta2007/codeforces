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

int H,W;

vector<vint>calc(){
    vector<vint>A;

    rep(i,H){
        vint v;
        if(i%2==0||W==4){
            for(int j=1;j<W;j+=2)v.pb(i*W+j);
            for(int j=0;j<W;j+=2)v.pb(i*W+j);
            if(i%2==1)reverse(all(v));
        }
        else{

            for(int j=0;j<W;j+=2)v.pb(i*W+j);
            for(int j=1;j<W;j+=2)v.pb(i*W+j);
        }
        A.pb(v);
    }
    return A;
}

bool check(vector<vint>&A){
    bool ok=true;
rep(i,H){
    rep(j,W){
            if(i+1!=H){
                int y,x,yy,xx;
                y=A[i][j]/W;
                x=A[i][j]%W;
                yy=A[i+1][j]/W;
                xx=A[i+1][j]%W;
                if(abs(y-yy)+abs(x-xx)==1)ok=false;
            }
            if(j+1!=W){
                int y,x,yy,xx;
                y=A[i][j]/W;
                x=A[i][j]%W;
                yy=A[i][j+1]/W;
                xx=A[i][j+1]%W;
                if(abs(y-yy)+abs(x-xx)==1)ok=false;
            }
        }
}
    return ok;
}

signed main(){

    cin>>H>>W;

    bool f=false;
    if(H>=4){
        swap(H,W);
        f=true;
    }


    if(W>=4){
        vector<vint>A=calc();
        if(f){
            vector<vint>B(W,vint(H));
            rep(i,H)rep(j,W){
                int y=A[i][j]/W;
                int x=A[i][j]%W;
                swap(x,y);
                B[j][i]=y*H+x;
            }
            A=B;
            swap(H,W);
        }


        assert(check(A));
        puts("YES");
        rep(i,H){
            rep(j,W){
                if(j)printf(" ");
                printf("%lld",A[i][j]+1);
            }puts("");
        }
        return 0;
    }



    vint ord;
    rep(i,H*W)ord.pb(i);
    do{
        vector<vint>A(H,vint(W));
        rep(i,H)rep(j,W)A[i][j]=ord[i*W+j];
        if(!check(A))continue;
        puts("YES");rep(i,H){
                rep(j,W){
                    if(j)printf(" ");
                    printf("%lld",A[i][j]+1);
                }puts("");
            }
            return 0;
    }while(next_permutation(all(ord)));
    puts("NO");
    return 0;
}