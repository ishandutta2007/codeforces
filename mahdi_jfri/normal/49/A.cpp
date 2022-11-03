#include <iostream>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    int c=a.size()-2;
    while(a[c]==' ' && c>=0)
        {c--;}
    char d;
    if(c>-1)
    d=a[c];
    if(d=='a' ||  d == 'o' || d == 'i' || d=='y' || d=='e' || d=='A' ||  d == 'O' || d == 'E' || d=='Y' || d=='I' || d=='u' || d=='U')
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}