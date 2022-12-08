#include <stdio.h>
#include <set>
using namespace std;

set<int> hor,ver;
multiset<int> hc,vc;

int main()
{
    int w,h,n; scanf ("%d %d %d",&w,&h,&n);
    ver.insert(0);
    ver.insert(w);
    vc.insert(w);
    hor.insert(0);
    hor.insert(h);
    hc.insert(h);
    while (n--){
        char s[3]; int x; scanf ("%s %d",s,&x);
        if (s[0] == 'H'){
            set<int>::iterator I = hor.lower_bound(x);
            set<int>::iterator J = I; J--;
            int p = *J, q = *I;
            hc.erase(hc.find(q-p));
            hor.insert(x);
            hc.insert(q-x);
            hc.insert(x-p);
        }
        else{
            set<int>::iterator I = ver.lower_bound(x);
            set<int>::iterator J = I; J--;
            int p = *J, q = *I;
            vc.erase(vc.find(q-p));
            ver.insert(x);
            vc.insert(q-x);
            vc.insert(x-p);
        }
        long long h = *hc.end().operator--();
        long long v = *vc.end().operator--();
        printf ("%lld\n",h*v);
    }
    return 0;
}