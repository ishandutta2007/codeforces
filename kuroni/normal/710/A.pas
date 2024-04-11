var chr: char;
    n: longint;
begin
  readln(chr,n);
  if (chr = 'a') or (chr = 'h') then if (n in [2..7]) then write(5) else write(3)
  else if (n in [2..7]) then write(8) else write(5);
end.