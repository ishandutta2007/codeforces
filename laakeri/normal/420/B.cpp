#include <iostream>
#include <vector>

using namespace std;

int ty[100001];
int nu[100001];

int ish[100001];

vector<int> eihuoneessa;

int ei[100001];

int main(){
    int huoneessa=0;
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a;
        char c;
        cin>>c>>a;
        if (c=='+'){
            ty[i]=1;
            if (ish[a]==0){
                eihuoneessa.push_back(a);
            }
            ish[a]=1;
        }
        if (c=='-'){
            ty[i]=2;
            if (ish[a]==0){
                ish[a]=1;
                huoneessa++;
            }
        }
        nu[i]=a;
    }
    if (huoneessa>0){
        for (int b:eihuoneessa){
            ei[b]=1;
        }
        eihuoneessa.clear();
    }
    for (int i=0;i<m;i++){
        int a=nu[i];
        if (ty[i]==1){
            if (huoneessa>0){
                ei[a]=1;
            }
            for (int b:eihuoneessa){
                if (b!=a){
                    ei[b]=1;
                }
            }
            eihuoneessa.clear();
            huoneessa++;
        }
        else{
            huoneessa--;
            if (huoneessa>0){
                ei[a]=1;
            }
            if (ei[a]==0){
                eihuoneessa.push_back(a);
            }
        }
    }
    int v=0;
    for (int i=1;i<=n;i++){
        if (!ei[i]){
            v++;
        }
    }
    cout <<v<<endl;
    for (int i=1;i<=n;i++){
        if (!ei[i]){
            cout <<i<<" ";
        }
    }
    cout <<endl;
}