uses math;
var n: longint;
    t: int64;
    num, dec: ansistring;

procedure Add;
var i: longint;
begin
  num := '0' + num;
  i := length(num);
  while num[i] = '9' do
  begin
    num[i] := '0';
    i := i - 1;
  end;
  num[i] := chr(ord(num[i]) + 1);
  if num[1] = '0' then delete(num,1,1);
end;

procedure Round(t: longint);
var r, tmp, i: longint;
begin
  if dec = '' then exit;
  r := 200001;
  for i := 5 to 9 do
  begin
    tmp := pos(chr(i+48),dec);
    if tmp > 0 then r := min(r,tmp);
  end;
  if r > 200000 then exit;
  tmp := 1;
  while (tmp < t) and (r > 1) and (dec[r-1] = '4') do
  begin
    tmp := tmp + 1;
    r := r - 1;
  end;
  dec := copy(dec,1,r-1);
  if dec = '' then
  begin
    Add;
    exit;
  end
  else
  begin
    dec[length(dec)] := chr(ord(dec[length(dec)]) + 1);
    exit;
  end;
end;

begin
  readln(n,t);
  readln(dec);
  if pos('.',dec) = 0 then begin write(dec); halt; end;
  num := copy(dec,1,pos('.',dec)-1);
  delete(dec,1,pos('.',dec));
  Round(t);
  if dec = '' then write(num) else write(num,'.',dec);
end.