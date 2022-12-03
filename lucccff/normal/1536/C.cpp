#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,q;
    char c;
    map <pair <int,int>,int> p;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        p.clear();
        k=0;
        getchar();
        for(j=1;j<=n;j++) {
            c=getchar();
            if (c=='D') {
                m=0;
            }
            else {
                m=1;
            }
            k+=m;
            l=__gcd(k,j);
            if (p.count(make_pair(k/l,j/l))) {
                q=p[make_pair(k/l,j/l)]+1;
                p[make_pair(k/l,j/l)]=q;
            }
            else {
                q=p[make_pair(k/l,j/l)]=1;
            }
            cout<<q<<' ';
        }
        cout<<endl;
    }
    return 0;
}