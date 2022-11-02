#include <iostream>
using namespace std;

int main()
{
    string names[5]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    int n, m=1;
    cin >> n;
    while (n-5*m>0)
    {
        n-=5*m;
        m*=2;
    }
    for (int i=0; i<5; i++)
    {
        n-=m;
        if (n<=0)
        {
            cout << names[i] << endl;
            return 0;
        }
    }
}