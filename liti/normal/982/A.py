n = int(input())
s = input()
s = '0' + s + '0'
print ("Yes" if s.count('11') == 0 and s.count('000') == 0 else 'No')