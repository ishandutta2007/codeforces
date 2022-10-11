#include <bits/stdc++.h>

using namespace std;

main()
{
    int A[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}, i, j;
    bool check = false;
    string str;
    for (i = 0; i < 15; i++)
    {
        cout<<A[i]<<endl;
        getline(cin,str);
        if (str == "yes") check = true;
        if (check == true) break;
    }
    if ((check == false) || (i >= 4))
    {
        cout<<"prime"<<endl;
        fflush(stdout);
    }
    else
    {
        check = false;
        for (j = i; j < 15; j++)
        {
            cout<<A[i]*A[j]<<endl;
            getline(cin,str);
            if (str == "yes") check = true;
            if ((check == true) || (A[i]*A[j+1] > 100)) break;
        }
        if (check == false)
        {
            cout<<"prime"<<endl;
            fflush(stdout);
        }
        else
        {
            cout<<"composite"<<endl;
            fflush(stdout);
        }
    }
}