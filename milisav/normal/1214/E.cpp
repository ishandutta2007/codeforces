#include<bits/stdc++.h>
#define maxn 800000
using namespace std;
int n;
int d[maxn];
pair<int,int> a[maxn];
vector<pair<int,int> > edges;
int mapping[maxn];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&d[i]);
        a[i-1]={d[i],i};
    }
    sort(a,a+n);
    int ind;
    int l;
    int q=-1;
    int p=0;
    int rem=0;
    int r = 2*n;
    for(int i=n-1;i>=0;i--) {
        ind = a[i].second;
        l = a[i].first;
        if(q==-1) {
            q=l;
            rem=l-1;
            mapping[p] = 2*ind;
            mapping[q] = 2*ind-1;
            for(int j=0;j<q;j++) {
                edges.push_back({j,j+1});
            }
        }
        else {
            if(rem>0) {
                if(q-p==l) {
                    p++;
                    q++;
                    mapping[p] = 2*ind;
                    mapping[q] = 2*ind-1;
                    edges.push_back({q-1,q});
                }
                else {
                    p++;
                    r++;
                    mapping[p] = 2*ind;
                    mapping[r] = 2*ind-1;
                    edges.push_back({p+l-1,r});
                }
                rem--;
            }
            else {
                if(l==1) {
                    q++;
                    mapping[q] = 2*ind;
                    edges.push_back({q-1,q});
                    q++;
                    mapping[q] = 2*ind-1;
                    edges.push_back({q-1,q});
                }
                else {
                    r++;
                    mapping[r] = 2*ind;
                    edges.push_back({0,r});
                    r++;
                    mapping[r] = 2*ind-1;
                    edges.push_back({l-2,r});
                }
            }
        }
    }
    for(auto x:edges) {
        printf("%d %d\n",mapping[x.first],mapping[x.second]);
    }
    return 0;
}