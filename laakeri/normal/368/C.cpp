#include <iostream>
#include <string>

using namespace std;
int numsx[100000];
int numsy[100000];
int numsz[100000];
int main () {
    string in;
    cin >> in;
    int i;
    int ii;
    int t;
    int l;
    int r;
    int xs;
    int ys;
    int zs;
    int low;
    xs=0;
    ys=0;
    zs=0;
    for (i=0;i<in.size();i++){
        if (in.substr(i,1)=="x"){
            xs++;
        }
        if (in.substr(i,1)=="y"){
            ys++;
        }
        if (in.substr(i,1)=="z") {
            zs++;
        }
        numsx[i]=xs;
        numsy[i]=ys;
        numsz[i]=zs;
    }
    string sub;
    cin >> t;
    for (i=0;i<t;i++){
        cin >> l;
        cin >> r;
        xs=0;
        ys=0;
        zs=0;
        if (r-l<2){
            cout << "YES" << endl;
        }
        else {
            xs=numsx[r-1]-numsx[l-1];
            ys=numsy[r-1]-numsy[l-1];
            zs=numsz[r-1]-numsz[l-1];
            if (in.substr(l-1,1)=="x"){
                xs++;
            }
            if (in.substr(l-1,1)=="y"){
                ys++;
            }
            if (in.substr(l-1,1)=="z"){
                zs++;
            }
            /*
            sub=in.substr(l-1,r-l+1);
            for (ii=0;ii<sub.size();ii++){
                if (sub.substr(ii,1)=="x"){
                    xs++;
                }
                if (sub.substr(ii,1)=="y"){
                    ys++;
                }
                if (sub.substr(ii,1)=="z") {
                    zs++;
                }
            }
            */
            low=max (max(xs,ys),zs)-min(min(xs,ys),zs);
            if (low<2){
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}