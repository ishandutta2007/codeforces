#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int a[5][5];
pair<int,int> b[5][5];


int main()
{
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++ ) 
    {
        string s;
        cin >> s; 
        int x; 
        switch( s[0] ) 
        {
            case 'R':
                x = 0;
                break;
            case 'G':
                x = 1; 
                break;
            case 'B':
                x = 2;
                break;
            case 'W': 
                x = 3;
                break;
            case 'Y':
                x = 4;
                break;
            default:
                break;
        }
        int y = s[1] - '1';
        if( a[x][y] == 0 ) 
        a[x][y] = 1;
    }

    int bAns = 10;
    for(int i = 0 ; i < (1<<10) ;i++ )
    {
        memset( b, 0, sizeof b ) ; 
        int num = i;
        for(int j = 0 ; j < 5; j++ ) 
        {
            if( num & 1 ) 
                for(int k = 0 ; k  < 5; k++ )
                    b[j][k].first = j + 1; 
            num/=2;
        }
        for(int j = 0 ; j < 5; j++ ) 
        {
            if( num & 1 ) 
                for(int k = 0 ; k  < 5; k++ )
                    b[k][j].second = j + 1; 
            num/=2;
        }

        vector< pair<int, int> > s;
        for(int k =  0 ; k < 5 ; k++ ) 
            for(int j = 0 ; j < 5 ;j++ ) 
                if( a[k][j] ) 
                    s.push_back( b[k][j] ) ; 
        sort( s.begin() , s.end() ) ; 
        int sz = s.size() ; 
        if( unique( s.begin() , s.end() ) - s.begin() == sz ) 
            bAns = min( bAns, __builtin_popcount( i ) ) ; 
    }
    cout << bAns << endl;
}