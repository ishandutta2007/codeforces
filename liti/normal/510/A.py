n, m = map(int,input().split())
print(  '\n'.join(([ '#'*m, '.'*(m-1)+'#', '#'*m, '#'+(m-1)*'.' ] * ((n+3)//4) )[:n] ) )