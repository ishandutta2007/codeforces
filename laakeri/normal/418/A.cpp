#include <iostream>
#include <vector>

using namespace std;

int used[1001][1001];

vector<pair<int,int> > v;

int main(){
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        int f=0;
        for (int ii=1;ii<=n;ii++){
            if (i!=ii&&used[min(i,ii)][max(i,ii)]==0){
                v.push_back(make_pair(i,ii));
                used[min(i,ii)][max(i,ii)]=1;
                f++;
            }
            if (f==k) break;
        }
        if (f<k){
            cout <<-1<<endl;
            return 0;
        }
    }
    cout <<v.size()<<endl;
    for (auto asd:v){
        cout <<asd.first<<" "<<asd.second<<'\n';
    }
}