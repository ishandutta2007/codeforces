#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    string a, b;
    
    cin >> a >> b;
    
    if(a.length() != b.length())
    {
                  cout << "NO";
                  return 0;
    }
    
    int i = 0;
    
    while(a[i] == b[i])
               ++i;
               
    int j = i + 1;
    
    while(j < a.length() && a[j] == b[j])
            ++j;
            
    if(j == a.length())
    {
         cout << "NO";
         return 0;
    }
    
    swap(a[i], a[j]);
    
    if(a == b)
         cout << "YES";
    else
        cout << "NO";
        
    return 0;
}