s=->{gets.split.map &:to_i}
l,r = s[]
def cc(x,l,r,m)
    return 0 if x > r
    (x >= l ? 1 : 0) + cc(m*x,l,r,m) + (m == 2 ? cc(3*x,l,r,3) : 0)
end

puts cc(1,l,r,2)