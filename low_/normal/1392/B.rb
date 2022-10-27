def get_max(a)
	res = a[0]
	for i in 1..(a.length-1)
		if a[i] > res
			res = a[i]
		end
	end
	res
end

def flip_array!(a)
	m = get_max(a)
	for i in 0..(a.length-1)
		a[i] = m - a[i]
	end
	nil
end

t = gets.chomp.to_i
for tc in 1..t
	a = gets.split
	n = a[0].to_i
	k = a[1].to_i
	a = gets.split
	for i in 0..(n-1)
		a[i] = a[i].to_i
	end
	flip_array!(a)
	
	if (k%2 == 0) 
		flip_array!(a)
	end
	for i in 0..(n-1)
		print(a[i])
		print(" ")
	end
	print("\n")
end