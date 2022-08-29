#include <iostream>
#include <cstring>
using namespace std;


char c[100500];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%s", c);
    int l = strlen(c);
    int x = l;
    
    for (int i = 0; i < l - 1; i++)
    {
        if (c[i] == '0')
        {
            x = i + 1;
            break;
        }
        printf("%c", c[i] );
    }
    printf("%s", c + x);

    return 0;
}