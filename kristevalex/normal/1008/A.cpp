#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

string text;


int main()
    {
    FAST;

    cin >> text;

    int n = text.size()-1;



    for (int i = 0; i < text.size()-1; i++)
        {
        if (text[i] != 'a' && text[i] != 'o' && text[i] != 'i' && text[i] != 'u' && text[i] != 'e' && text[i] != 'a' && text[i] != 'n')
            if (text[i+1] != 'a' && text[i+1] != 'o' && text[i+1] != 'i' && text[i+1] != 'u' && text[i+1] != 'e' && text[i+1] != 'a')
                {
                cout << "NO";
                return 0;
                }

        }


    if (text[n] != 'a' && text[n] != 'o' && text[n] != 'i' && text[n] != 'u' && text[n] != 'e' && text[n] != 'a'&& text[n] != 'n')
                {
                cout << "NO";
                return 0;
                }

    cout << "YES";

    return 0;
    }