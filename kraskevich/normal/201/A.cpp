#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    if(n == 3)
        cout << 5;
    else
        for(int i = 1;; i += 2)
            if((i * i + 1) / 2 >= n)
            {
                cout << i;
                break;
            }
    
    return 0;
}