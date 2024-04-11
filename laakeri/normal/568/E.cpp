#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int a[101010];
int ccr[202020];
int v[101010];

const int N=1<<18;
int st[2*N];

int lol[N];

int getmax(int aa, int bb){
    aa+=N;
    bb+=N;
    int m=0;
    while (aa<=bb){
        if (aa%2) m=max(m, st[aa++]);
        if (!(bb%2)) m=max(m, st[bb--]);
        aa/=2;
        bb/=2;
    }
    return m;
}

void setmax(int i, int x){
    for (i+=N;i;i/=2){
        st[i]=max(st[i], x);
    }
}

void build(){
    for (int i=N-1;i;i--){
        st[i]=max(st[i*2], st[i*2+1]);
    }
}

int cnt(vector<int>&x, int l, int r){
    if (r<l) return 0;
    return upper_bound(x.begin(), x.end(), r)-lower_bound(x.begin(), x.end(), l);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    set<int> ccs;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]>0){
            ccs.insert(a[i]);
        }
    }
    int m;
    cin>>m;
    vector<int> b(m);
    multiset<int> bb;
    for (int i=0;i<m;i++){
        cin>>b[i];
        ccs.insert(b[i]);
    }
    map<int, int> ccm;
    int i2=1;
    for (int c:ccs){
        ccr[i2]=c;
        ccm[c]=i2++;
    }
    for (int i=1;i<=n;i++){
        if (a[i]>0){
            a[i]=ccm[a[i]];
        }
    }
    n+=2;
    a[0]=0;
    a[n-1]=i2;
    for (int i=0;i<(int)b.size();i++){
        b[i]=ccm[b[i]];
        bb.insert(b[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i=0;i<n;i++){
        if (a[i]>-1){
            v[i]=getmax(0, a[i]-1)+1;
            setmax(a[i], v[i]);
        }
        else{
            lol[0]=st[N];
            for (int j=1;j<N;j++){
                lol[j]=max(lol[j-1], st[j+N]);
            }
            for (int t:b){
                st[t+N]=max(st[t+N], lol[t-1]+1);
            }
            build();
        }
    }
    int tv=v[n-1];
    int vk=n-1;
    int qq=0;
    int vv=a[n-1];
    for (int i=n-2;i>=0;i--){
        if (a[i]>-1&&a[i]<vv){
            if (min(cnt(b, a[i]+1, a[vk]-1), qq)>=tv-v[i]-1){
                int ne=tv-v[i]-1;
                for (int j=vk-1;j>i;j--){
                    if (ne>0&&a[j]==-1){
                        auto it=bb.lower_bound(vv);
                        it--;
                        vv=*it;
                        a[j]=*it;
                        bb.erase(it);
                        ne--;
                    }
                }
                vv=a[i];
                vk=i;
                tv=v[i];
                qq=0;
            }
        }
        else if(a[i]==-1){
            qq++;
        }
    }
    for (int i=1;i<n-1;i++){
        if (a[i]==-1){
            auto it=bb.begin();
            a[i]=(*it);
            bb.erase(it);
        }
    }
    for (int i=1;i<n-1;i++){
        cout<<ccr[a[i]]<<" ";
    }
}