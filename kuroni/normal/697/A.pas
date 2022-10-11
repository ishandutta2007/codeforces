var t,x,s: longint;
begin
  read(t,x,s);
  if s < t+x then if s = t then write('YES') else write('NO')
  else
    if ((s-t) mod x = 0) or ((s-t) mod x = 1) then write('YES') else write('NO');
end.