#include <iostream>
using namespace std;

int main()
{
    int n, k, s[50];
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> s[i];
    int t = s[k-1], num=0;
    for (int i=0; i<n; i++)
        if (s[i]>0 && s[i]>=t) num++;
    cout << num << endl;
}