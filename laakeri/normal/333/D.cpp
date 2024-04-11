#include <iostream>
#include <vector>

using namespace std;

int n,m;

int ma[1001][1001];

vector<int> lols[1001];
int fo[1001];

int test(int x){
    for (int i=0;i<m;i++) lols[i].clear();
    for (int i=0;i<n;i++){
        for (int ii=0;ii<n;ii++) fo[ii]=0;
        for (int ii=0;ii<m;ii++){
            if (ma[i][ii]>=x){
                for (int a:lols[ii]){
                    if (fo[a]) return 1;
                    else fo[a]=1;
                }
                lols[ii].push_back(i);
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++) cin>>ma[i][ii];
    }
    int mi=0;
    int ma=1e9;
    while (mi<=ma){
        int mid=(mi+ma)/2;
        if (test(mid)){
            mi=mid+1;
        }
        else{
            ma=mid-1;
        }
    }
    cout<<ma<<endl;
}