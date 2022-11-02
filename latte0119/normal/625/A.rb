n=gets.to_i
a=gets.to_i
b=gets.to_i
c=gets.to_i

if a<=b-c||b>n then
    puts n/a
    exit(0)
end

n-=b
ans=n/(b-c)+1
n%=b-c
n+=c
ans+=n/a

puts ans