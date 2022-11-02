#include <iostream>

using namespace std;

int sh[100001];
int st[202020];

int N=100001;

void add(int i, int x){
    for (i+=N;i;i/=2) st[i]+=x;
}
int sum(int a, int b){
    a+=N;
    b+=N;
    int s=0;
    while (a<=b){
        if (a%2) s+=st[a++];
        if (!(b%2)) s+=st[b--];
        a/=2;
        b/=2;
    }
    return s;
}

int l,r,cf;

int gc(int i){
    if (cf) return r-i;
    return l+i;
}

int main(){
    int n,q;
    cin>>n>>q;
    cf=0;
    for (int i=0;i<n;i++){
        sh[i]=1;
        add(i, 1);
    }
    l=0;
    r=n-1;
    for (int i=0;i<q;i++){
        int qt;
        cin>>qt;
        if (qt==1){
            int p;
            cin>>p;
            if (p*2>r-l+1){
                int ii=p-1;
                for (int iii=p;iii<r-l+1;iii++,ii--){
                    //cout<<"a2 "<<gc(iii)<<" "<<gc(ii)<<endl;
                    sh[gc(ii)]+=sh[gc(iii)];
                    add(gc(ii), sh[gc(iii)]);
                }
                if (cf) l+=(r-l+1)-p;
                else r-=(r-l+1)-p;
                cf=1-cf;
            }
            else{
                int ii=p*2-1;
                for (int iii=0;iii<p;iii++,ii--){
                    //cout<<"a "<<gc(iii)<<" "<<gc(ii)<<endl;
                    sh[gc(ii)]+=sh[gc(iii)];
                    add(gc(ii), sh[gc(iii)]);
                }
                if (cf) r-=p;
                else l+=p;
            }
        }
        else{
            int a,b;
            cin>>a>>b;
            cout<<sum(min(gc(a), gc(b-1)), max(gc(a), gc(b-1)))<<endl;
        }
    }
}