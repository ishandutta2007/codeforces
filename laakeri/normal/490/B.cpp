#include <iostream>
#include <map>

using namespace std;

map<int, int> bf;
map<int, int> af;
map<int, int> used;

int v[200001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if (a==0) a=-1;
        if (b==0) b=-1;
        af[a]=b;
        bf[b]=a;
        if (a>=0) used[a]=0;
        if (b>=0) used[b]=0;
    }
    for (auto lol:used){
        if (bf[lol.first]==0){
            int xx=lol.first;
            int i=0;
            while (xx>0){
                v[i]=xx;
                i+=2;
                xx=af[xx];
            }
        }
        if (bf[lol.first]==-1){
            int xx=lol.first;
            int i=1;
            while (xx>0){
                v[i]=xx;
                i+=2;
                xx=af[xx];
            }
        }
    }
    for (int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}