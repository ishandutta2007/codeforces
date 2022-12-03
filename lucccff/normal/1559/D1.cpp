#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int size1[100010],fa1[100010];  //  1

void makeSet1(int size) {
    for (int i = 1; i <= size; i++) {
        fa1[i] = i;  // i
        size1[i]=1;
    }
    return;
}

int find1(int x) {
    if (x != fa1[x])  // xx
        fa1[x] = find1(fa1[x]);  // x,
    return fa1[x];
}

void unionSet1(int x, int y) {
    int xx = find1(x), yy = find1(y);
    if (xx == yy) return;
    if (size1[xx] > size1[yy])  // 
        swap(xx, yy);
    fa1[xx] = yy;
    size1[yy] += size1[xx];
}

int size2[100010],fa2[100010];  //  1

void makeSet2(int size) {
    for (int i = 1; i <= size; i++) {
        fa2[i] = i;  // i
        size2[i]=1;
    }
    return;
}

int find2(int x) {
    if (x != fa2[x])  // xx
        fa2[x] = find2(fa2[x]);  // x,
    return fa2[x];
}

void unionSet2(int x, int y) {
    int xx = find2(x), yy = find2(y);
    if (xx == yy) return;
    if (size2[xx] > size2[yy])  // 
        swap(xx, yy);
    fa2[xx] = yy;
    size2[yy] += size2[xx];
}

map <pair<pair<int,int>,pair<int,int>>,int> p;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m1,m2,n,t;
    long long a[100010],b[100010],d[100010][2];
    pair <int,int> c[100010];
    cin>>n>>m1>>m2;
    makeSet1(n);
    for(i=0;i<m1;i++) {
        cin>>k>>l;
        unionSet1(k,l);
    }
    makeSet2(n);
    for(i=0;i<m2;i++) {
        cin>>k>>l;
        unionSet2(k,l);
    }
    k=0;
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            if (find1(i)!=find1(j)&&find2(i)!=find2(j)) {
                d[k][0]=i;
                d[k][1]=j;
                k++;
                unionSet1(i,j);
                unionSet2(i,j);
            }
        }
    }
    cout<<k<<endl;
    for(i=0;i<k;i++) {
        cout<<d[i][0]<<' '<<d[i][1]<<endl;
    }
    return 0;
}