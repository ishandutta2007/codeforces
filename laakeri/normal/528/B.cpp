#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
map<int, int> ccv;

const int N=1<<19;
int st[2*N];
void setv(int i, int x){
    for (i+=N;i;i/=2){
        st[i]=max(st[i], x);
    }
}
int getmax(int a, int b){
    a+=N;
    b+=N;
    int v=0;
    while (a<=b){
        if (a%2) v=max(v, st[a++]);
        if (!(b%2)) v=max(v, st[b--]);
        a/=2;
        b/=2;
    }
    return v;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<int> cc;
    int n;
    cin>>n;
    vector<pair<int, int> > cs(n);
    for (int i=0;i<n;i++){
        cin>>cs[i].F>>cs[i].S;
        cc.insert(cs[i].F-cs[i].S);
        cc.insert(cs[i].F+cs[i].S);
        cs[i].F=cs[i].S+cs[i].F;
    }
    int i2=0;
    for (int a:cc){
        ccv[a]=i2++;
    }
    int mv=0;
    sort(cs.begin(), cs.end());
    for (auto a:cs){
        int v=getmax(0, ccv[a.F-a.S*2]);
        setv(ccv[a.F], v+1);
        mv=max(mv, v+1);
    }
    cout<<mv<<endl;
}