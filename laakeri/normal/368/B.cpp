#include <iostream>
#include <vector>

using namespace std;

vector<int> a2;
int n;
int m;
int l;
bool numment[100000];
int main () {
    cin >> n;
    cin >> m;
    int a[n];
    int d[n];
    int i;
    int ii;
    int nums;
    int dif=0;
    bool f;
    for (i=0;i<n;i++){
        cin >> a[i];
    }
    for (i=0;i<n;i++){
        f=false;
        /*
        for (ii=0;ii<a2.size();ii++){
            if (a[n-i-1]==a2[ii]){
                f=true;
                break;
            }
        }
        if (!f){
            a2.push_back(a[n-i-1]);
            dif++;
            d[n-i-1]=dif;
        }
        else {
            d[n-i-1]=dif;
        }
        */
        if (!numment[a[n-i-1]]){
            dif++;
            numment[a[n-i-1]]=true;
        }
        d[n-i-1]=dif;
    }
    for (i=0;i<m;i++){
        nums=0;
        cin >> l;
        l=l-1;
        cout << d[l] << endl;
    }
}