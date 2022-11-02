#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;

ll MOD=1000000009;

int n,m;

ll s[2010100];
ll la[2010100];
ll lb[2010100];

ll fs[300011];
ll ivs[300011];

int N=303030;

ll getiv(int a, int b){
    if (a==0) return ivs[b];
    else {
        ll r=ivs[b]-ivs[a-1];
        if (r<0) r+=MOD;
        return r;
    }
}

struct ma{
    ll m[2][2]={{0, 1}, {1, 1}};
    void operator*=(const ma &m2){
        ll nm[2][2];
        for (int i=0;i<2;i++){
            for (int ii=0;ii<2;ii++){
                ll s=0;
                for (int iii=0;iii<2;iii++){
                    s+=(m[i][iii]*m2.m[iii][ii])%MOD;
                    s%=MOD;
                }
                nm[i][ii]=s;
            }
        }
        for (int i=0;i<2;i++)
            for (int ii=0;ii<2;ii++) m[i][ii]=nm[i][ii];
    }
    ma operator+(const ma &m2){
        ma nm;
        for (int i=0;i<2;i++)
            for (int ii=0;ii<2;ii++)
                nm.m[i][ii]=(m[i][ii]+m2.m[i][ii])%MOD;
        return nm;
    }
    void pr(){
        for (int i=0;i<2;i++){
            for (int ii=0;ii<2;ii++){
                cout<<m[i][ii]<<" ";
            }
            cout<<endl;
        }
    }
};

ma fma[300011];
ma fmas[300011];

ll fibo (int i, ll s1, ll s2){
    if (i<1) return s1;
    return ((fma[i-1].m[0][0]*s1)%MOD+(fma[i-1].m[0][1]*s2)%MOD)%MOD;
}

ll fibosum (int a, int b, ll s1, ll s2){
    ll h,l;
    if (a<1){
        l=0;
    }
    else if (a<2){
        l=s1;
    }
    else{
        l=(s1+(fmas[a-2].m[0][0]*s1)%MOD+(fmas[a-2].m[0][1]*s2)%MOD)%MOD;
    }
    if (b<1){
        h=s1;
    }
    else {
        h=(s1+(fmas[b-1].m[0][0]*s1)%MOD+(fmas[b-1].m[0][1]*s2)%MOD)%MOD;
    }
    ll r=h-l;
    if (r<0) r+=MOD;
    return r;
}

void upd2 (int i, int na, int nb){
    if (la[i]>0||lb[i]>0){
        //cout<<"upd "<<i<<" "<<na<<" "<<nb<<" "<<la[i]<<" "<<lb[i]<<" "<<fibosum(0, nb-na, la[i], lb[i])<<endl;
        s[i]+=fibosum(0, nb-na, la[i], lb[i]);
        s[i]%=MOD;
        if (nb-na>0){
            //cout<<"lol "<<i*2<<" "<<i*2+1<<endl;
            int nm=(na+nb)/2;
            la[i*2]+=la[i];
            lb[i*2]+=lb[i];
            la[i*2+1]+=fibo(nm+1-na, la[i], lb[i]);
            lb[i*2+1]+=fibo(nm+1-na+1, la[i], lb[i]);
            la[i*2]%=MOD;
            lb[i*2]%=MOD;
            la[i*2+1]%=MOD;
            lb[i*2+1]%=MOD;
        }
    }
    la[i]=0;
    lb[i]=0;
}

void upd (int i, int na, int nb, int qa, int qb, int f){
    if (na>nb) return;
    if (na>qb||nb<qa) return;
    int nm=(na+nb)/2;
    if (na>=qa&&nb<=qb){
        //cout<<"l "<<na<<" "<<nb<<" "<<qa<<" "<<qb<<" "<<f<<endl;
        la[i]+=fs[f];
        lb[i]+=fs[f+1];
        la[i]%=MOD;
        lb[i]%=MOD;
    }
    else{
        //cout<<"u "<<na<<" "<<nb<<" "<<qa<<" "<<qb<<" "<<f<<" "<<fibosum(0, min(nb, qb)-max(na, qa), fs[f], fs[f+1])<<endl;
        s[i]+=fibosum(0, min(nb, qb)-max(na, qa), fs[f], fs[f+1]);
        s[i]%=MOD;
        int lol=0;
        if (qa+f<nm+1){
            lol=nm+1-qa-f;
        }
        //cout<<qa<<" "<<qb<<" "<<nm+1<<" "<<nb<<" "<<lol+f<<endl;
        upd(i*2, na, nm, qa, qb, f);
        upd(i*2+1, nm+1, nb, qa, qb, f+lol);
    }
}

ll sum (int i, int na, int nb, int qa, int qb){
    if (na>nb) return 0ll;
    if (na>qb||nb<qa) return 0ll;
    int nm=(na+nb)/2;
    upd2(i, na, nb);
    if (na>=qa&&nb<=qb){
        //cout<<"rs "<<i<<" "<<na<<" "<<nb<<" "<<qa<<" "<<qb<<" "<<s[i]<<endl;
        return s[i];
    }
    else{
        return (sum(i*2, na, nm, qa, qb)+sum(i*2+1, nm+1, nb, qa, qb))%MOD;
    }
}

void q1(int l, int r){
    upd(1, 0, N, l-1, r-1, 0);
}
ll q2(int l, int r){
    return (sum(1, 0, N, l-1, r-1)+getiv(l-1, r-1))%MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll f1=0;
    ll f2=1;
    for (int i=0;i<300010;i++){
        fs[i]=f2;
        ll f3=(f1+f2)%MOD;
        f1=f2;
        f2=f3;
    }
    for (int i=0;i<300010;i++){
        fma[i+1]*=fma[i];
        fmas[i+1]=fma[i+1]+fmas[i];
    }
    int n,m;
    cin>>n>>m;
    ll s=0;
    for (int i=0;i<n;i++){
        ll a;
        cin>>a;
        s+=a;
        s%=MOD;
        ivs[i]=s;
    }
    for (int i=0;i<m;i++){
        int q;
        cin>>q;
        int a,b;
        cin>>a>>b;
        if (q==1) q1(a, b);
        else cout<<q2(a, b)<<'\n';
    }
}