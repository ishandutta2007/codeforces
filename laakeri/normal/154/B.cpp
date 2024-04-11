#include <iostream>
#include <set>

using namespace std;

int d[100001];

int co[100001];

set<int> lol[100001];

int on[100001];

int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for (int i=2;i<=100000;i++){
        if (d[i]==0){
            for (int ii=i;ii<=100000;ii+=i){
                d[ii]=i;
            }
        }
    }
    for (int i=0;i<m;i++){
        char o;
        int a;
        cin>>o>>a;
        if (o=='+'){
            if (on[a]){
                cout<<"Already on\n";
                continue;
            }
            int f=0;
            int aa=a;
            int con=0;
            while (aa>1){
                if (co[d[aa]]){
                    f=1;
                    con=*(lol[d[aa]].begin());
                    break;
                }
                else{
                    aa/=d[aa];
                }
            }
            if (f){
                cout<<"Conflict with "<<con<<'\n';
            }
            else{
                aa=a;
                while (aa>1){
                    co[d[aa]]++;
                    lol[d[aa]].insert(a);
                    aa/=d[aa];
                }
                cout<<"Success\n";
                on[a]=1;
            }
        }
        else{
            if (on[a]==0){
                cout<<"Already off\n";
                continue;
            }
            on[a]=0;
            int aa=a;
            while (aa>1){
                co[d[aa]]--;
                lol[d[aa]].erase(a);
                aa/=d[aa];
            }
            cout<<"Success\n";
        }
    }
}