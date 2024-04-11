n = int(input())
a = ['I hate', 'I love'] * ( (n+1) // 2 )
print( ' that '.join(a[:n]) + ' it' )