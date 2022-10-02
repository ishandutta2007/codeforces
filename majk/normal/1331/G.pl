for (my $i=0; $i <= 10; $i++) { $var = readline (*STDIN );
chomp ($var );
push (@seq, $var)}
;
for (my $i=0; $i <= 10; $i++) { $var = pop (@seq );
 $aresult = sqrt ( abs ( $var));
 $bresult =  ( ($var ** 3) * 5);
 $result =  ($aresult + $bresult);
if ( (400 >= $result)) {printf (STDOUT 'f(%d) = %.2f', $var, $result);
print (STDOUT "\n")}
;
if ( (400 < $result)) {printf (STDOUT 'f(%d) = MAGNA NIMIS!', $var);
print (STDOUT "\n")}
}