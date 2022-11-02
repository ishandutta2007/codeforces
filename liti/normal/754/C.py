def pr( name , lvl , dp , u , tot ): 
    if lvl == 0:
        print(name + ':' + tot[lvl])
        return

    pr( u[lvl][name] , lvl - 1 , dp , u , tot )
    print(name + ':' + tot[lvl])

def solve(): 
    n = int(input())
    users = input().split()
    m = int(input())
    dp = [] 
    u = []
    tot = [] 
    for i in range( m ) : 
        dp.append( set() ) 
        u.append( {} ) 
        line = input().split(':')
        sender = line[0]
        tot.append( line[1] ) 
        line[1] = line[1].replace( '?' , ' ' )
        line[1] = line[1].replace( '.' , ' ' )
        line[1] = line[1].replace( ',' , ' ' )
        line[1] = line[1].replace( '!' , ' ' )
        mess = line[1].split()

        if sender == '?' : 
            if i != 0:
                for name in users:
                    for x in dp[i-1]: 
                        if x != name and name not in mess:
                            dp[i].add( name ) 
                            u[i][name] = x
            else : 
                for name in users: 
                    if name not in mess:
                        dp[i].add( name ) 
        else: 
            if i != 0: 
                for x in dp[i-1]: 
                    if x != sender: 
                        dp[i].add( sender ) 
                        u[i][sender] = x
            else: 
                dp[i].add( sender )
        
        
    if dp[m-1]: 
        pr( list(dp[m-1])[0] , m-1 , dp , u , tot )
    else: 
        print("Impossible")


t = int(input())
for i in range( t ) : 
    solve()