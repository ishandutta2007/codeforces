#include <iostream>
#include <vector>

using namespace std;

const int N=101010;
int st[2*N];

int bit[40];

int bp[100002][40];
int bm[100002][40];

int get(int a, int b){
    int v=-1;
    a+=N;
    b+=N;
    while (a<=b){
        if (a%2){
            if (v==-1) v=st[a];
            else v&=st[a];
            a++;
        }
        if (!(b%2)){
            if (v==-1) v=st[b];
            else v&=st[b];
            b--;
        }
        a/=2;
        b/=2;
    }
    return v;
}

struct qu{
    int l,r,v;
};

int main(){
    vector<qu> qs;
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int l,r,q;
        cin>>l>>r>>q;
        for (int ii=0;ii<31;ii++){
            if (q&(1<<ii)){
                bp[l][ii]++;
                bm[r+1][ii]++;
            }
        }
        qu qq;
        qq.l=l;
        qq.r=r;
        qq.v=q;
        qs.push_back(qq);
    }
    for (int i=0;i<2*N;i++) st[i]=-1;
    for (int i=1;i<=n;i++){
        for (int ii=0;ii<31;ii++){
            if (bp[i][ii]) {
                bit[ii]+=bp[i][ii];
            }
            if (bm[i][ii]) {
                bit[ii]-=bm[i][ii];
            }
        }
        st[i+N]=0;
        for (int ii=0;ii<31;ii++){
            if (bit[ii]){
                st[i+N]|=(1<<ii);
            }
        }
    }
    for (int i=N-1;i>0;i--){
        if (st[i*2]==-1){
            st[i]=st[i*2+1];
        }
        else if(st[i*2+1]==-1){
            st[i]=st[i*2];
        }
        else{
            st[i]=st[i*2]&st[i*2+1];
        }
    }
    for (qu q:qs){
        if (get(q.l, q.r)!=q.v){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++){
        if (st[i+N]>-1) cout<<st[i+N]<<" ";
        else cout<<0<<" ";
    }
}