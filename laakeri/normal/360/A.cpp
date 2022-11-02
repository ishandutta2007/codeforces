#include <iostream>
#include <vector>

using namespace std;

int maxv[5001];
int vk[5001];
int v[5001];

struct q{
    int t,l,r,d;
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<q> qs;
    for (int i=0;i<m;i++){
        q a;
        cin>>a.t>>a.l>>a.r>>a.d;
        qs.push_back(a);
    }
    for (int i=qs.size()-1;i>=0;i--){
        q a=qs[i];
        if (a.t==1){
            for (int ii=a.l;ii<=a.r;ii++){
                maxv[ii]-=a.d;
            }
        }
        if (a.t==2){
            for (int ii=a.l;ii<=a.r;ii++){
                if (vk[ii]){
                    maxv[ii]=min(maxv[ii], a.d);
                }
                else{
                    vk[ii]=1;
                    maxv[ii]=a.d;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        v[i]=maxv[i];
    }
    for (int i=0;i<qs.size();i++){
        q a=qs[i];
        if (a.t==1){
            for (int ii=a.l;ii<=a.r;ii++){
                v[ii]+=a.d;
            }
        }
        if (a.t==2){
            int f=0;
            for (int ii=a.l;ii<=a.r;ii++){
                if (v[ii]==a.d){
                    f=1;
                }
            }
            if (!f){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++){
        cout<<maxv[i]<<" ";
    }
}