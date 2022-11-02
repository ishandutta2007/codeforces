#include <iostream>
using namespace std;

int main()
{
    int a[4], d;
    bool b[100001];
    for (int i=1; i<=100000; i++) b[i]=false;
    for (int i=0; i<4; i++) cin >> a[i];
    cin >> d;
    for (int i=0; i<4; i++)
    {
        for (int j=a[i]; j<=d; j+=a[i])
        {
            b[j]=true;
        }
    }
    int n=0;
    for (int i=1; i<=d; i++) n+=b[i];
    cout << n << endl;
}