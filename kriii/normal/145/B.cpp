#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int a,b,c,d;

int main()
{
    int i;

    scanf ("%d %d %d %d",&a,&b,&d,&c);

    if (c > a || d > a || c > b || d > b) printf ("-1");
    else if (c == d){
        if (c == a){
            if (b < a + 1) printf ("-1");
            else{
                for (i=0;i<a;i++) printf ("74");
                for (i=0;i<b-a;i++) printf ("7");
            }
        }
        else{
            for (i=0;i<a-c;i++) printf ("4");
            for (i=0;i<c-1;i++) printf ("74");
            for (i=0;i<b-c+1;i++) printf ("7");
            printf ("4");
        }
    }
    else if (c == d + 1){
        printf ("7");
        for (i=0;i<a-d;i++) printf ("4");
        for (i=0;i<d-1;i++) printf ("74");
        for (i=0;i<b-d;i++) printf ("7");
        printf ("4");
    }
    else if (c + 1 == d){
        for (i=0;i<a-c;i++) printf ("4");
        for (i=0;i<c;i++) printf ("74");
        for (i=0;i<b-c;i++) printf ("7");
    }
    else printf ("-1");

    return 0;
}