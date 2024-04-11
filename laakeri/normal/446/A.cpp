#include <iostream>

using namespace std;

int vs[100001];

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>vs[i];
    int v=0;
    int wc=0;
    int wcl=0;
    int woc=0;
    int wocl=0;
    for (int i=0;i<n;i++){
        int a=vs[i];
        if (a>wc){
            wc=a;
            wcl++;
        }
        else{
            wc=a;
            wcl=1;
        }
        if (a>woc){
            woc=a;
            wocl++;
        }
        else{
            wc=woc+1;
            wcl=wocl+1;
            woc=a;
            wocl=1;
        }
        //cout <<wc<<" "<<wcl<<" "<<woc<<" "<<wocl<<endl;
        v=max(v,wcl);
    }
    wc=0;
    wcl=0;
    woc=0;
    wocl=0;
    //cout<<"lol"<<endl;
    for (int i=0;i<n;i++){
        int a=vs[i];
        if (a>wc){
            wc=a;
            wcl++;
        }
        else{
            wc=a;
            wcl=1;
        }
        if (a>woc){
            woc=a;
            wocl++;
        }
        else{
            if (i>1){
                if (vs[i-2]<a-1){
                    wc=a;
                    wcl=wocl+1;
                }
                else{
                    wc=a;
                    wcl=2;
                }
            }
            else{
                wc=a;
                wcl=wocl+1;
            }
            woc=a;
            wocl=1;
        }
        //cout <<wc<<" "<<wcl<<" "<<woc<<" "<<wocl<<endl;
        v=max(v,wcl);
    }
    cout<<v<<endl;
}