type bigNum = ansistring;

var a, b: bignum;
    str: ansistring;

begin
  read(str);
  a := copy(str,1,pos(' ',str)-1);
  delete(str,1,pos(' ',str));
  b := str;
  if a = b then write(a) else write('1');
end.