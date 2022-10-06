#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
#define inf 1000000007
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
int d[2010];
int pre[2010];
int main(){
    int n;
    cin >> n;
    vector<int> a(2*n);
    rep(i,2*n) cin >> a[i];
    int id = -1;
    rep(i,2*n){
        if(a[i]==1){
            id = i;
        }
    }
    Fill(d,inf);
    queue<int> q;
    d[id] = 0;
    q.push(id);
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        if(x%2==0){
            if(d[x+1]>d[x]+1){
                d[x+1] = d[x]+1;
                q.push(x+1);
                pre[x+1] = 0;
            }
        }else{
            if(d[x-1]>d[x]+1){
                d[x-1] = d[x]+1;
                q.push(x-1);
                pre[x-1] = 0;
            }
        }
        if(x<n){
            if(d[x+n]>d[x]+1){
                d[x+n] = d[x]+1;
                q.push(x+n);
                pre[x+n] = 1;
            }
        }else{
            if(d[x-n]>d[x]+1){
                d[x-n] = d[x]+1;
                q.push(x-n);
                pre[x-n] = 1;
            }
        }
    }
    if(d[0]==inf){
        cout << -1 << endl;
        return 0;
    }
    vector<int> b(2*n);
    rep(i,2*n){
        b[i] = i+1;
    }
    id = 0;
    while(d[id]>0){
        if(pre[id]==0){
            rep(i,n){
                swap(b[2*i],b[2*i+1]);
            }
            if(id%2==0){
                id += 1;
            }else{
                id -= 1;
            }
        }else{
            rep(i,n){
                swap(b[i],b[i+n]);
            }
            if(id<n){
                id += n;
            }else{
                id -= n;
            }
        }
    }
    rep(i,2*n){
        if(a[i]!=b[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << d[0] << endl;
    return 0;
}