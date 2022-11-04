#include <iostream>

using namespace std;

int n;

int main(){
    
    cin >> n;
    if(n > 2 && n % 2 == 0)
        cout << "YES";
    else
        cout << "NO";
}