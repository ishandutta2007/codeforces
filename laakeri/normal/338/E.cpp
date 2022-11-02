#include <iostream>
#include <algorithm>
#define F first
#define S second

using namespace std;

int a[150001];

vector<int> los[150001];

int b[150001];

const int N=1<<18;

int st[2*N];
int lazy[2*N];
int from[2*N];

void init(int i, int sta, int stb){
    if (sta==stb) from[i]=sta;
    else{
        int m=(sta+stb)/2;
        init(i*2, sta, m);
        init(i*2+1, m+1, stb);
        from[i]=from[i*2];
    }
}

void add(int i, int sta, int stb, int a, int b, int v){
    if (b<sta||a>stb) return;
    if (sta>=a&&stb<=b){
        st[i]+=v;
        if (sta<stb) lazy[i]+=v;
    }
    else{
        int m=(sta+stb)/2;
        if (lazy[i]){
            add(i*2, sta, m, sta, m, lazy[i]);
            add(i*2+1, m+1, stb, m+1, stb, lazy[i]);
            lazy[i]=0;
        }
        add(i*2, sta, m, a, b, v);
        add(i*2+1, m+1, stb, a, b, v);
        st[i]=min(st[i*2], st[i*2+1]);
        if (st[i*2]<st[i*2+1]) from[i]=from[i*2];
        else from[i]=from[i*2+1];
    }
}

const int inf=1e9;

pair<int, int> getmin(int i, int sta, int stb, int a, int b){
    if (b<sta||a>stb) return {inf, 0};
    if (sta>=a&&stb<=b){
        return {st[i], from[i]};
    }
    else{
        int m=(sta+stb)/2;
        if (lazy[i]){
            add(i*2, sta, m, sta, m, lazy[i]);
            add(i*2+1, m+1, stb, m+1, stb, lazy[i]);
            lazy[i]=0;
        }
        return min(getmin(i*2, sta, m, a, b), getmin(i*2+1, m+1, stb, a, b));
    }
}

int main(){
    init(1, 0, N-1);
    int n,l,h;
    cin>>n>>l>>h;
    for (int i=0;i<l;i++) cin>>b[i];
    for (int i=0;i<n;i++) cin>>a[i];
    sort(b, b+l);
    for (int i=0;i<n;i++){
        int mi=0;
        int ma=l-1;
        while (mi<=ma){
            int m=(mi+ma)/2;
            if (b[m]+a[i]>=h){
                ma=m-1;
            }
            else{
                mi=m+1;
            }
        }
        if (mi<l) los[mi].push_back(i);
    }
    int v=n-l+1;
    for (int i=0;i<l;i++){
        for (int lol:los[i]){
            add(1, 0, N-1, max(0, lol-l+1), lol, 1);
        }
        while (1){
            auto asd=getmin(1, 0, N-1, 0, n-l);
            if (asd.F<i+1){
                //cout<<asd.F<<" "<<asd.S<<endl;
                v--;
                add(1, 0, N-1, asd.S, asd.S, inf);
            }
            else break;
        }
    }
    cout<<v<<endl;
}