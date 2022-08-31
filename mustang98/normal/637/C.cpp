#include <iostream>
#include <string>

using namespace std;

string m[1001];

int main()
{
    int n,k,mink=150;//mink -       
    cin>>n;
    for (int i=0;i<n;i++) cin>>m[i];
    if (n==1) {cout<<6; return 0;}
    //     2   
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
        {
            k=0;
            for (int u=0;u<6;u++) if (m[i][u]!=m[j][u]) k++;
            if (k<mink) mink=k;
        }
    cout<<(mink-1)/2;
    /*
    k=1: answer = 0
    k=2: answer = 0
    k=3: answer = 1
    k=4: answer = 1
    k=5: answer = 2
    k=6: answer = 2
    */
    return 0;
}