#include <iostream>

using namespace std;

int n;
int d;
int m;
int i;
int ii;
int pay;
int minp;
int minpa;

int main()
{
    cin >> n;
    cin >> d;
    int a[n];
    for (i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> m;
    for (i=0;i<m;i++){
        if (i<n){
            minp=200;
            minpa=0;
            for (ii=0;ii<n;ii++){
                if (a[ii]<minp){
                    minp=a[ii];
                    minpa=ii;
                }
            }
            pay=pay+a[minpa];
            a[minpa]=300;
        }
        else {
            pay=pay-((m-n)*d);
            break;
        }
    }
    cout << pay << endl;
}