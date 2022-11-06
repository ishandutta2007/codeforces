#include <iostream>
using namespace std;

int main()
{
    int n,k,o,i[100001],pos=1,l[100001];
    cin>>n;
    for (k=0;k<=n;k++)
        i[k]=0;
    for (k=0;k<n;k++)
    {
        cin>>o;
        l[k]=o;
        if (o>n) i[0]++; else
        i[o]++;
    }
    for (k=0;k<n;k++){
        if (l[k]>n) {
            while (i[pos]!=0) pos++;
            i[l[k]]--;
            cout<<pos<<' ';
            pos++;
        } else
        if (i[l[k]]==1) cout<<l[k]<<' '; else{
            while (i[pos]!=0) pos++;
            i[l[k]]--;
            cout<<pos<<' ';
            pos++;
        }
    }
    return 0;
}