#include <iostream>
#include <vector>
using namespace std;
int main()
{
long long n;
cin >> n;
vector <long long> p(n);
for (long long i=0; i<n; i++)
{
    cin >> p[i];   
}
 for (long long i=0; i<n;i++)
 {
     if (p[i] % 2==0)
    cout << p[i] -1<< " ";
    else
    cout << p[i] << " ";
    
     
 }
    
}