var i,n,k,s:integer;
   
begin
  read(n);
  if n mod 2 =0 then 
  begin 
   for i:=1 to n div 2 do write(1);
  end
  else 
  begin
  write(7);
  for i:=1 to n div 2 -1 do write(1);
  end;
end.