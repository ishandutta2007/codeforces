#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

const int Z = 1 << 17;
map<int, int> xs[Z*2],ys[Z*2];
int k,q;

map<int, int> sum(map<int, int>&a, map<int, int>& b)
{
    map<int, int> res;
    map<int, int>::iterator I = a.begin(), J = b.begin();
    int nxt = 0;
    while (I != a.end() && J != b.end()){
        nxt = max(nxt,I->second);
        nxt = max(nxt,J->second);
        if (I->first == J->first) res[I->first] = nxt, I++, J++;
        else if (I->first < J->first) res[I->first] = nxt, I++;
        else res[J->first] = nxt, J++;
    }
    return res;
}

bool cont(map<int, int> &n, int l, int u)
{
    map<int, int>::iterator I = n.lower_bound(l);
    if (I == n.end()) return false;
    return I->second <= u;
}

bool good(map<int, int> it[], int s, int e, int l, int u)
{
    s += Z; e += Z;
    while (s < e){
        if (s & 1){
            if (!cont(it[s],l,u)) return false;
            s++;
        }
        if (~e & 1){
            if (!cont(it[e],l,u)) return false;
            e--;
        }
        s >>= 1;
        e >>= 1;
    }
    if (s == e) if (!cont(it[s],l,u)) return false;
    return true;
}

int main()
{
    scanf ("%*d %*d %d %d",&k,&q);
    for (int i=0;i<k;i++){
        int x,y;

        scanf ("%d %d",&x,&y);
        xs[x+Z][y] = y;
        ys[y+Z][x] = x;
    }
    for (int i=Z-1;i>=1;i--){
        xs[i] = sum(xs[i*2],xs[i*2+1]);
        ys[i] = sum(ys[i*2],ys[i*2+1]);
    }

    for (int i=0;i<q;i++){
        int a,b,c,d;
        scanf ("%d %d %d %d",&a,&b,&c,&d);

        if (good(xs,a,c,b,d) || good(ys,b,d,a,c)) puts("YES");
        else puts("NO");
    }

    return 0;
}